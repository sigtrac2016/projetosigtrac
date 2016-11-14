Run
---
```
docker run -it -h m2k --name m2k -e 'KAFKA=52.67.204.136' -e 'MQTT=52.67.204.136' -d m2k
```

Re-build
-----
```
docker rm -f m2k
docker rmi m2k
docker build -t m2k .
```
