# Docker image to be used as a development container
FROM gcc:latest
WORKDIR /root/
RUN mkdir -p /root/.ssh
COPY id_rsa /root/.ssh/id_rsa
COPY ssh_config /root/.ssh/config
RUN chmod 400 /root/.ssh/id_rsa
RUN GIT_SSH_COMMAND='ssh -i /root/.ssh/id_rsa' git clone git@github.com:jdraines/AOC2022.git
WORKDIR /root/AOC2022
CMD tail -f /dev/null