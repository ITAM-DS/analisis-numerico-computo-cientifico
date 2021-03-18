# For Kubeflow namespace next will deploy services:

Set:

```
OPT_LOAD_BALANCER_SERVICE=loadbalancer-opt-0.1-hostpath-pv
OPT_PV=hostpath-pv
OPT_PVC=hostpath-pvc
OPT_JUPYTERLAB_SERVICE=jupyterlab-opt-0.1-hostpath-pv
OPT_URL=https://raw.githubusercontent.com/ITAM-DS/analisis-numerico-computo-cientifico/master/deployments/minikube/
```

Next lines are not necessary but help to modify services:

```
wget $OPT_URL/hostpath_pv/$OPT_LOAD_BALANCER_SERVICE.yaml
wget $OPT_URL/hostpath_pv/$OPT_PV.yaml
wget $OPT_URL/hostpath_pv/$OPT_PVC.yaml
wget $OPT_URL/hostpath_pv/$OPT_JUPYTERLAB_SERVICE.yaml
```

Create storage:

```
kubectl create -f $OPT_URL/hostpath_pv/$OPT_PV.yaml
kubectl create -f $OPT_URL/hostpath_pv/$OPT_PVC.yaml
```

Create service:

```
kubectl create -f $OPT_URL/hostpath_pv/$OPT_LOAD_BALANCER_SERVICE.yaml
```

Create deployment:

```
kubectl create -f $OPT_URL/hostpath_pv/$OPT_JUPYTERLAB_SERVICE.yaml
```

To check set:

```
OPT_LOAD_BALANCER_SERVICE=$(echo $OPT_LOAD_BALANCER_SERVICE|sed -n 's/\./-/g;s/_/-/g;p')
OPT_JUPYTERLAB_SERVICE=$(echo $OPT_JUPYTERLAB_SERVICE|sed -n 's/\./-/g;s/_/-/g;p')
```

Describe:

```
kubectl describe service -n kubeflow $OPT_LOAD_BALANCER_SERVICE
kubectl describe pv -n kubeflow $OPT_PV
kubectl describe pvc -n kubeflow $OPT_PVC
kubectl describe deployment -n kubeflow $OPT_JUPYTERLAB_SERVICE
```

Describe all pods:

```
kubectl describe pods -n kubeflow
```

Scale: (if created automatically scale is 1)

```
kubectl scale deployment -n kubeflow $OPT_JUPYTERLAB_SERVICE --replicas=<0 or 1>
```

Delete:

```
kubectl delete service -n kubeflow $OPT_LOAD_BALANCER_SERVICE
kubectl delete pvc -n kubeflow $OPT_PVC
kubectl delete pv -n kubeflow $OPT_PV
kubectl delete deployment -n kubeflow $OPT_JUPYTERLAB_SERVICE 
```

# JUPYTERLAB SERVICE IS USING DOCKER IMAGE FROM NEXT [Dockerfile](https://github.com/palmoreck/dockerfiles/blob/master/jupyterlab/kale/opt/0.1/Dockerfile)


