FROM palmoreck/jupyterlab_c_kernel:1.1.0

ARG NB_USER=miuser
ARG NB_UID=1000

ENV USER ${NB_USER}
ENV NB_UID ${NB_UID}
ENV HOME /home/${NB_USER}

COPY . ${HOME}
USER root
RUN chown -R ${NB_UID} ${HOME}
USER ${NB_USER}

echo "alias python=python3" >> /home/${NB_USER}/.bash_aliases
