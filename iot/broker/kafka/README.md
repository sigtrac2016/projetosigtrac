Run
---

```bash
docker run -d -h zookeeper --name zookeeper zookeeper
docker run -d -h kafka --name kafka --link zookeeper:zookeeper -p 9092:9092 projetosigtrac/kafka
```

Environment Variable
---

- `ADVERTISED_HOSTNAME=<hostname for client connection>`: When a broker starts up, it registers its ip/port in ZK. You need to make sure the registered ip is consistent with what's listed in metadata.broker.list in the producer config. By default, the registered ip is given by InetAddress.getLocalHost.getHostAddress. Typically, this should return the real ip of the host. However, sometimes (e.g., in EC2), the returned ip is an internal one and can't be connected to from outside. The solution is to explicitly set the host ip to be registered in ZK by setting the "hostname" property in server.properties. This environment variable makes it happen.

View Log
---

```bash
docker logs -f zookeeper
docker logs -f kafka
```