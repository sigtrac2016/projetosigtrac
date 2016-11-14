Run
---

```
docker run -it -h m2k --name m2k -e 'KAFKA=IP_ZOOKEEPER' -e 'MQTT=IP_MQTT' -d projetosigtrac/m2k
```

View Log
---

```
docker logs -f m2k
```

Re-build
---

```
docker rm -f m2k
docker rmi m2k
docker build -t m2k .
```
