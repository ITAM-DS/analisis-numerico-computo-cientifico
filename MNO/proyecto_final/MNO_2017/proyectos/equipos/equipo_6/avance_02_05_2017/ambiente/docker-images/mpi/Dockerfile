FROM nvidia/cuda

MAINTAINER Adrián Vázquez <radianstk@gmail.com>

ENV REFRESHED_AT 2017-04-06

RUN \
    apt-get -qq update; apt-get upgrade -y -qq; \
    apt-get install -y -qq wget curl git jq nano man openssh-server; \
    apt-get clean && rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/*

ADD openmpi-2.0.2.tar.gz /opt/

RUN cd /opt/openmpi-2.0.2 && ./configure --prefix=/opt/openmpi-2.0.2 -with-sge && make all install

ENV PATH="/opt/openmpi-2.0.2/bin:$PATH"

ENV LD_LIBRARY_PATH="/opt/openmpi-2.0.2/lib:LD_LIBRARY_PATH"

CMD ["/bin/bash"]
