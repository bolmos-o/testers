#!/bin/bash

curl -I http://193.111.11.3

kubectl exec deploy/grafana -- pkill grafana
kubectl exec deploy/ftps -- pkill vsftpd
kubectl exec deploy/influxdb -- pkill influxd
kubectl exec deploy/mysql -- pkill mysqld
kubectl exec deploy/nginx -- pkill nginx
kubectl exec deploy/wordpress -- pkill nginx
kubectl exec deploy/wordpress -- pkill php-fpm7
kubectl exec deploy/pma -- pkill nginx
kubectl exec deploy/pma -- pkill php-fpm7
