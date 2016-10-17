Run
---

```bash
docker run -d -h zookeeper --name zookeeper zookeeper
docker run -d -h kafka --name kafka --link zookeeper:zookeeper -p 9092:9092 projetosigtrac/kafka
```

View Log
---

```bash
docker logs -f zookeeper
docker logs -f kafka
```
