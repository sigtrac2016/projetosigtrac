[![Docker Automated buil](https://img.shields.io/docker/automated/jrottenberg/ffmpeg.svg?style=flat-square)](https://hub.docker.com/r/projetosigtrac/mosquitto/) [![Docker Pulls](https://img.shields.io/docker/pulls/mashape/kong.svg?style=flat-square)](https://hub.docker.com/r/projetosigtrac/mosquitto/)

Run
---

```bash
docker run -d -h mqtt --name mqtt -p 1883:1883 projetosigtrac/mosquitto
```

View Log
---

```bash
docker logs -f mqtt
```
