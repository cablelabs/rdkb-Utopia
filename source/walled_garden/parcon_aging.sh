#!/bin/sh

# prepare allow list
EXPIRED_CLIENTS="/var/.parcon_expired_clients"
PARCON_EXPIRE_TIME=`sysevent get parcon_expire_time`
awk -F, -v expire=$PARCON_EXPIRE_TIME 'mktime($2)+expire<=systime(){print $1}' /var/.parcon_allow_list > $EXPIRED_CLIENTS
awk -F, -v expire=$PARCON_EXPIRE_TIME 'mktime($2)+expire>systime()' /var/.parcon_allow_list > /var/.parcon_allow_list_tmp

rm /var/.parcon_allow_list
mv /var/.parcon_allow_list_tmp /var/.parcon_allow_list

# reload iptables rules before deleting conntrack entries
firewall

# delete conntrack entries
for line in $(cat $EXPIRED_CLIENTS); do
    MAC=`echo -n $line`
    IP=`cat /var/parcon/$MAC`
    awk -F "[ =]+" /tcp.*$IP/'{system("conntrack_delete "$8" "$10" "$12" "$14)}' /proc/net/nf_conntrack
done

# delete cron entries
CRON_DIR="/var/spool/cron/crontabs"
ROOT_CRON="root"
TMP_FILE="tmp.root"

awk '!/parcon_aging/' /var/spool/cron/crontabs/root > $CRON_DIR/$TMP_FILE
awk -FT -v expire=$PARCON_EXPIRE_TIME '/parcon_aging/ && mktime($2)+expire>systime()' /var/spool/cron/crontabs/root >> $CRON_DIR/$TMP_FILE

rm $CRON_DIR/$ROOT_CRON
mv $CRON_DIR/$TMP_FILE $CRON_DIR/$ROOT_CRON

sysevent set crond-restart 1
