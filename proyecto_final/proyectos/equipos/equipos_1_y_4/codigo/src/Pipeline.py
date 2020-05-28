import Control as ctl
from models import particle_swarm as ps
from models import simulated_annealing as sa


if __name__ == "__main__":

    # El siguiente objeto, contiene el pipeline principal para:
    # Crear y cargar la base de datos
    # Transormar los datos a un formato adecuado de trabajo
    # Calcular las rutas de todas las fuerzas de ventas de manera secuencial
    objControl = ctl.Control()

    objControl.CargarBase()
    objControl.Transform()
    objControl.CalcularRutasPar(ps.ParticleSwarm, objControl.dict_Hiper_PS)
    objControl.grafo_Ejecucion.compute()
    objControl.CalcularRutasSeq(sa.SimulatedAnnealing, objControl.dict_Hiper_SA)
