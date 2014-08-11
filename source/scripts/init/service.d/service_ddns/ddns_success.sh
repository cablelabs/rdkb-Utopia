#!/bin/sh

#------------------------------------------------------------------
# Copyright (c) 2008 by Cisco Systems, Inc. All Rights Reserved.
#
# This work is subject to U.S. and international copyright laws and
# treaties. No part of this work may be used, practiced, performed,
# copied, distributed, revised, modified, translated, abridged, condensed,
# expanded, collected, compiled, linked, recast, transformed or adapted
# without the prior written consent of Cisco Systems, Inc. Any use or
# exploitation of this work without authorization could subject the
# perpetrator to criminal and civil liability.
#------------------------------------------------------------------

# This is called by ez-ipupdate upon successful update of the
# DDNS Server

source /etc/utopia/service.d/date_functions.sh
source /etc/utopia/service.d/ulog_functions.sh


DDNS_HOSTNAME=`syscfg get ddns_hostname`
DDNS_SERVICE=`syscfg get ddns_service`
ulog ddns status "ddns client reports successful update of $DDNS_HOSTNAME with service $DDNS_SERVICE"
WAN_IFADDR=`sysevent get current_wan_ipaddr`

syscfg set wan_last_ipaddr "$WAN_IFADDR"

CURRENT_TIME=`get_current_time`
syscfg set ddns_last_update "$CURRENT_TIME"
syscfg commit
