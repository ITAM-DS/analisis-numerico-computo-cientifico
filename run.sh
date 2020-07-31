#!/bin/bash
NB_USER=jovyan
HOME=/home/${NB_USER}
cd ${HOME}

exec "$@"
