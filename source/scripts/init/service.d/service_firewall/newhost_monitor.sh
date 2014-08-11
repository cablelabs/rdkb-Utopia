#/bin/sh

#------------------------------------------------------------------
# Copyright (c) 2009 by Cisco Systems, Inc. All Rights Reserved.
#
# This work is subject to U.S. and international copyright laws and
# treaties. No part of this work may be used, practiced, performed,
# copied, distributed, revised, modified, translated, abridged, condensed,
# expanded, collected, compiled, linked, recast, transformed or adapted
# without the prior written consent of Cisco Systems, Inc. Any use or
# exploitation of this work without authorization could subject the
# perpetrator to criminal and civil liability.
#------------------------------------------------------------------


# ----------------------------------------------------------------------------
# This script monitors /var/log/messages for utopia triggers.
# When it finds them it will inform the trigger handler
#
# ----------------------------------------------------------------------------

source /etc/utopia/service.d/ulog_functions.sh
source /etc/utopia/service.d/event_handler_functions.sh

SERVICE_NAME="firewall_newhost_monitor"


TRIGGER_HANDLER=newhost

TRIGGER_FILENAME=newhost_input.${$}
TRIGGER_FILE=/tmp/${TRIGGER_FILENAME}                                           
TRIGGER_LOG=/var/log/messages                                                 
TRIGGER_OLDFILES="/tmp/newhost_input.*"
TRIGGER_PIDFILE="/tmp/newhost_monitor.pid"
# Note. keep the string UTOPIA.TRIGGER in sync with firewall.c
LOG_TRIGGER_PREFIX="UTOPIA.TRIGGER"

service_start()
{
   # if a younger instantiation of this script is running, then we kill it
   ps | awk -v "PID=$$" '/newhost_input/ && !/'"$$"'/  { if ($1<PID) system("kill -9 "$1);}'

   # we also remove any lingering files used by that script
   rm -Rf $TRIGGER_OLDFILES
   echo "${$}" > $TRIGGER_PIDFILE

   # link our file to the log file
   ln  -sf  $TRIGGER_LOG $TRIGGER_FILE

   PID=$$
   ulog newhosts status "$PID starting newhost monitoring process"
   tail -f -n 0 $TRIGGER_FILE | awk -f /etc/utopia/service.d/service_firewall/log_reader.awk $LOG_TRIGGER_PREFIX &
   sysevent set ${SERVICE_NAME}-status started
}

service_stop() {
   killall trigger
   sysevent set ${SERVICE_NAME}-status stopped
}

case "$1" in
   ${SERVICE_NAME}-start)
      service_start
      ;;
   ${SERVICE_NAME}-stop)
      service_stop
      ;;
   ${SERVICE_NAME}-restart)
      service_stop
      service_start
      ;;
   #----------------------------------------------------------------------------------
   # Add other event entry points here
   #----------------------------------------------------------------------------------
   syslog_rotated)
      # if this is a signal that the syslog has been rotated
      # then ignore it if we are not actively monitoring at this time
      if [ "syslog_rotated" = "$1" ] ; then
         ulog newhosts status "$PID newhost monitor informed about log rotation event"
         if [ ! -f "$TRIGGER_PIDFILE" ] ; then
            exit 0 ;
         fi
      fi
      service_start
      ;;

   *)
      echo "Usage: $SERVICE_NAME [ ${SERVICE_NAME}-start | ${SERVICE_NAME}-stop | ${SERVICE_NAME}-restart]" >&2
      exit 3
      ;;
esac
