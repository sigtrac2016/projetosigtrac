FROM node:latest

RUN mkdir -p /usr/src/api
WORKDIR /usr/src/api
COPY . /usr/src/api

EXPOSE 8080
RUN npm install
CMD ["npm", "start"]
