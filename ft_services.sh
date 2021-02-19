#!/bin/bash

find srcs/ -name Dockerfile
cat srcs/*/Dockerfile | grep FROM

curl -I http://192.168.49.3

kubectl exec deploy/grafana -- pkill grafana
kubectl exec deploy/ftps -- pkill vsftpd
kubectl exec deploy/influxdb -- pkill influxd
kubectl exec deploy/mysql -- pkill mysqld
kubectl exec deploy/nginx -- pkill nginx
kubectl exec deploy/wordpress -- pkill nginx
kubectl exec deploy/wordpress -- pkill php-fpm7
kubectl exec deploy/pma -- pkill nginx
kubectl exec deploy/pma -- pkill php-fpm7
