tablas hash


una tabla hash o de dispercion es una estructura de datos de acceso en la que cada elemento tiene asociada
una llave por medio de la cual se consulta 

esto de espresa mediante el siguiente formalismo: <llave1->elem1,llave2->elem2,...,llaveN->elemN>

una tabla sin elementos se denomina vacia

al numero de elementos presentes en la tabla se le conoce como tamaño de la tabla

una llave es una cadena de varacteres alfanumerico con un significado especial en el mundo en el cual ocurre el problema, 
las llaves so unicas al interior de la tabla y son el unico medio a travez del cual se tiene acceso, a la informacion asociada

el conjunto de todas las llavez posibles se le denomina, espacio de llaves al interior de una tabla hash no existe la nocion de orden

el espacio fisico de la representacion de la informacion se le conoce como area primaria de la tabla 

ejemplo:

cuantas llaves se pueden generas si estas se forman de la sig manera: inicial del nombre,inicial del apellido,año de ingreso(3 digitos),
semestre(2 digitos),4 numeros consecutivos,
27*27*1000*100*10000=729,000,000,000.  posibles llaves.

una funcionde hashing o dispersion es una funcion h()que proyecta un valor del espacio de llaves a una direccion del area primaria.

una funcion hash no preserva orden.

cuando dos llavez distintasson proyectadas sobre la misma direccion del area primaria, tenemos una colision.

el factor de carga de una tabla hash se define como el tamaño de la tabla sobre su capacidad y es una medida de lo saturadaque esta se encuentra

el desempeño de una tabla hash comienza a disminuir a medida que aumenta el factor de carga.

otros elementos a considerar son la funcion hash o de dispercion y la capacidad de las tablas.



espec Tabla

constructoras:
IniciaTablaH: int->TablaH
InsTablaH: TablaH,Llave,Elem->TablaH

observadoras:}
InfoTablaH:TablaH.Llave->Elem
EstaEnTablaH:TablaH,Llave->int
