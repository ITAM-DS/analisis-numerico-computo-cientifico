#based in: https://github.com/palmoreck/dockerfiles-for-binder/tree/jupyterlab_optimizacion
FROM palmoreck/jupyterlab_optimizacion_binder_test:2.1.4
ARG NB_USER=jovyan
ARG NB_UID=1000
ENV USER ${NB_USER}
ENV NB_UID ${NB_UID}
ENV HOME /home/${NB_USER}
COPY . ${HOME}
USER root
RUN chown -R ${NB_UID} ${HOME}

USER ${NB_USER}

RUN ["sudo", "chmod", "+x", "/home/jovyan/run.sh"]

ENTRYPOINT ["/home/jovyan/run.sh"]
