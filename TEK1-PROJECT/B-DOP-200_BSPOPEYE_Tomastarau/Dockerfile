FROM debian:buster-slim

RUN apt-get update && apt-get install -y curl && \
    curl -sL https://deb.nodesource.com/setup_14.x | bash && \
    apt-get install -y nodejs

RUN mkdir -p /usr/src/app
WORKDIR /usr/src/app

COPY package.json /usr/src/app
COPY app.js /usr/src/app

RUN npm install

EXPOSE 3000

CMD ["npm", "start"]