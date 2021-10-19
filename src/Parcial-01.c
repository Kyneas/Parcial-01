/*
 ============================================================================

 Una empresa de recolección y reciclado de plásticos requiere un sistema que les permita administrar
sus clientes y pedidos de recolección. El programa contará con el siguiente menú:

1) Alta de cliente: Se da de alta un cliente con nombre de la empresa, cuit, dirección y localidad. Se generará
un ID único para este cliente que se imprimirá por pantalla si el alta es correcta.

ecliente:
nombre
cuit
direccion
localidad
id unico

2) Modificar datos de cliente: Se ingresa el ID de cliente y se permitirá cambiar la dirección y la localidad.

3) Baja de cliente: Se ingresa el ID del cliente. Luego se preguntará si se quiere confirmar la eliminación.

4) Crear pedido de recolección: Se imprimirán los clientes por pantalla y se pedirá que se ingrese el ID de un
cliente existente y la cantidad de kilos totales que se recolectarán del cliente. Se generará un ID para el pedido y
el mismo quedará en estado “Pendiente” hasta que se obtengan los residuos del cliente y se trasladen a la
empresa.

epedido:
kilos totales
id pedido PK
id cliente FK
estado pendiente - completado
HDPE
LDPE
PP


5) Procesar residuos: Se elegirá esta opción cuando los residuos que volvieron a la empresa se hayan
procesado y separado en los diferentes tipos de plástico que la empresa puede reciclar. Se imprimirán los
pedidos por pantalla y se pedirá seleccionar el ID de uno de ellos. Luego deberán ingresarse la cantidad de kilos
de plástico de cada uno de los 3 tipos que la empresa puede procesar que se obtuvieron de los kilos totales que
se recolectaron. Por último, se marcará al pedido como “Completado”.

6) Imprimir Clientes: Se imprimirá una lista de clientes con todos sus datos junto con la cantidad de “pedidos
de recolección” que posee en estado “Pendiente”.

7) Imprimir Pedidos pendientes: Se imprimirá una lista de los pedidos que se encuentren en estado
“Pendiente” con la información: Cuit del cliente, dirección del cliente, cantidad de kilos a recolectar.

8) Imprimir Pedidos procesados: Se imprimirá una lista de los pedidos que se encuentren en estado
“Completado” con la información: Cuit del cliente, dirección del cliente, cantidad de kilos reciclados de cada tipo
de plástico.

9) Ingresar una localidad e indicar la cantidad de pedidos pendientes para dicha localidad.

10) Cantidad de kilos de polipropileno reciclado promedio por cliente. (kilos totales / cantidad de clientes)

Los tipos de plástico que la empresa puede reciclar son:
• HDPE: Polietileno de alta densidad (Envases para lácteos, perfumes, detergentes líquidos, etc.)
• LDPE: Polietileno de baja densidad (Bolsas de congelación de alimentos, tapas flexibles o bolsas de
basura.)
• PP: Polipropileno (Plásticos utilizados en la industria automovilística y en la construcción.)
El resto de la basura recolectada es desechada

Recomendaciones:
• Agregar al campo “isEmpty” a cada entidad.
• Generar un ID auto incrementable para cada entidad.
• Antes de comenzar, realizar un diagrama con las entidades, todos sus campos y cómo se
relacionan.
• Antes de comenzar, realizar las funciones para imprimir cada uno de los arrays con todos sus
campos (sin relacionarlos con los otros arrays) para poder probar los ABM.
• Para poder probar los informes, realizar funciones que carguen con datos falsos los arrays de
las entidades, y ejecutarlas al comenzar el programa.

Nota 0: El sistema soportará una capacidad máxima de 100 clientes y 1000 pedidos
Nota 1: Se deberán desarrollar bibliotecas por cada entidad (Cliente y Pedido) las cuales contendrán las funciones (Alta,
Baja, Modificar, etc.).Los informes deberán estar en una biblioteca aparte.
Nota 2: El código deberá tener comentarios con la documentación de cada una de las funciones y respetar las reglas de estilo
de la cátedra.

Continuar el examen previo:
1) Agregar la entidad Localidad.
2) Refactorizar las funciones que considere necesarias para que utilicen la nueva entidad.
3) Agregar los siguientes informes:
a) Cliente con más pedidos pendientes.
b) Cliente con más pedidos completados.

Nota 1: Se deberán desarrollar bibliotecas por cada entidad las cuales contendrán las funciones (Alta, Baja, Modificar, etc.).
Los informes deberán estar en una biblioteca aparte.
Nota 2: El código deberá tener comentarios con la documentación de cada una de las funciones y respetar las reglas de estilo
de la cátedra.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "inputs.h"
#include "cliente.h"
#include "pedido.h"
#include "nexo.h"

#define TAM 5
#define LEN 8
#define LARGO 21

int main(void) {
	setbuf(stdout,NULL);

	int opcion;
	int clienteNuevoOK;
	int idCliente;
	int borrarClienteOK;
	int pedidoNuevoOK;
	int idPedido;
	int procesarPedidoOK;
	int localidad;
	int totalLocalidadesOK;
	int posLocalidad;
	float promedioPP;
	int bajaLocalidadOK;
	int modificacionClienteOK;


	eCliente clientes[TAM]={{100, "Coca", 20124325001, "Falsa 123", 1, 0},{102, "Manaos", 20120075433, "Fake 345", 2, 0},
			                {103, "Pesi", 20124640905, "Una 345", 4, 0},{104, "Tai", 20854600437, "Aqueia 987", 1, 0},
						    {105, "Cordoba", 20854436539, "Esa 127", 9, 0}};

	ePedido pedidos[LEN] = {{201, 250, 105, 1, 0,0,0,0},{202, 450, 100, 2, 200,100,153,0},
							{203, 1020, 105, 2, 500,300,220,0},{204, 770, 100, 2, 200,300,270,0},
							{205, 300, 103, 1, 0,0,0,0},{206, 766, 102, 2, 500,100,187,0},
							{207, 803, 103, 1, 0,0,0,0},{208, 144, 102, 2, 50,50,44,0}};


	eLocalidad localidades[LARGO] = {{1,"Lomas de Zamora", 0},{2,"Banfield", 0},{3,"Temperley", 0},{4,"Llavallol", 0},{5,"Turdera", 0},
									{6,"Villa Centenario", 0},{7,"Villa Fiorito", 1},{8,"Ingeniero Budge", 0},{9,"Gerli", 0},
									{10,"Lanús", 0}, {11,"Monte Chingolo", 0},{12,"Remedios de Escalada", 1},{13,"Valentín Alsina", 0},
									{14,"Avellaneda", 1},{15,"Crucecita", 0},{16,"Dock Sud", 0},{17,"Gerli", 0},{18,"Piñeyro", 0},
									{19,"Sarandí", 0},{20,"Villa Domínico", 0},{21,"Wilde", 0}};

//	eCliente clientes[TAM];
//	ePedido pedidos[LEN];
//	eLocalidad localidades[LARGO];
//
//	InicializarListaClientes(clientes, TAM);
//	InicializarListaPedidos(pedidos, LEN);
//	InicializarListaLocalidades(localidades, LARGO);


	do
		{
			printf("\n\n1.Alta cliente"
				   "\n2.Modificar cliente"
				   "\n3.Baja cliente"
				   "\n4.Crear pedido recoleccion"
				   "\n5.Procesar Residuos"
				   "\n6.Imprimir Clientes"
				   "\n7.Imprimir pedidos pendientes"
				   "\n8.Imprimir pedidos procesados"
				   "\n9.Buscar pedidos pendientes para una localidad"
				   "\n10.Promedio de kg de polipropileno por cliente"
				   "\n11.Cliente con más pedidos pendientes."
				   "\n12.Cliente con más pedidos completados."
				   "\n13.Alta Localidad."
				   "\n14.Baja Localidad"
				   "\n15.Modificar Localidad"
				   "\n0.SALIR");

			opcion = PedirEnteroEnRango("\nIngrese opcion: ", "\nError, opcion fuera de rango. Reintente: ", 0, 15);

			switch(opcion)
			{
				case 1:

					if (HayLocalidad(localidades, LARGO))
					{
						clienteNuevoOK = AltaCliente(clientes, TAM, localidades, LARGO);

						if(clienteNuevoOK >= 0)
						{
							printf("\nCliente dado de alta correctamente con el ID %d.", clienteNuevoOK);
						}
						else if (clienteNuevoOK == -1)
						{
							printf("\nError, la lista de clientes esta llena.");
						}
						else if (clienteNuevoOK == -3)
						{
							printf("\nCarga cancelada.");
						}
						else
						{
							printf("\nError al realizar la carga");
						}

					}
					else
					{
						printf("\nError, no hay localidades cargadas.");
					}



					break;
				case 2:
					if(HayCliente(clientes, TAM))
					{
						MostrarListaClientes(clientes, TAM, localidades, LARGO);

						idCliente = PedirEnteroPositivo("\nIngrese el ID del cliente que quiere modificar.", "\nError.");

						modificacionClienteOK = ModificarCliente(clientes, TAM, localidades, LARGO, idCliente);

						if(modificacionClienteOK == 0)
						{
							printf("\nCliente modificado con exito.");
						}
						else if (modificacionClienteOK == -2)
						{
							printf("\nModificación cancelada.");
						}
						else
						{
							printf("\nNo hay clientes activos con el ID %d.",idCliente);
						}

					}
					else
					{
						printf("\nNo hay clientes cargados en el sistema.");
					}

					break;
				case 3:
					if(HayCliente(clientes, TAM))
					{
						MostrarListaClientes(clientes, TAM, localidades, LARGO);

						idCliente = PedirEnteroPositivo("\nIngrese el ID del cliente que quiere dar de baja.", "\nError.");

						if(BuscarPosicionClientePorID(clientes, TAM, idCliente) != -1)
						{
							printf("\nConfirma la baja del usuario con el ID %d? (Tambien se daran de baja todos sus pedidos)", idCliente);
							opcion = PedirSN("\nS/N: ", "\nError, S/N: ");

							if(opcion)
							{
								borrarClienteOK = BajaClienteV2(clientes, TAM, pedidos, LEN, idCliente);

								if(borrarClienteOK == 0)
								{
									printf("\nEl cliente con el ID %d fue dado de baja exitosamente.", idCliente);

								}else
								{
									printf("\nError al realizar la baja.");
								}
							}else
							{
								printf("\nSolicitud de baja cancelada.");
							}
						}else
						{
							printf("\nNo hay cliente activo con el ID %d.",idCliente);
						}

					}else
					{
						printf("\nNo hay clientes cargados en el sistema.");
					}
					break;
				case 4:
					if(HayCliente(clientes, TAM))
					{
						MostrarListaClientes(clientes, TAM, localidades, LARGO);

						idCliente = PedirEnteroPositivo("\nIngrese el ID del cliente del cual se hara la recoleccion.", "\nError.");

						if(BuscarPosicionClientePorID(clientes, TAM, idCliente) != -1)
						{

							pedidoNuevoOK = NuevoPedido(pedidos, LEN, idCliente);

							if(pedidoNuevoOK > 0)
							{
								printf("\nPedido cargado exitosamente con el ID %d.", pedidoNuevoOK);
							}
							else if (pedidoNuevoOK == -1)
							{
								printf("\nError, la lista de pedidos esta llena.");
							}
							else
							{
								printf("\nError al cargar el pedido.");
							}
						}else
						{
							printf("\nNo hay cliente activo con el ID %d.",idCliente);
						}
					}else
					{
						printf("\nNo hay clientes cargados en el sistema.");
					}
					break;
				case 5:
					if(HayPedidoPendiente(pedidos, LEN))
					{
						MostrarListaPedidosPendientes(pedidos, LEN);

						idPedido = PedirEnteroPositivo("\nIngrese el ID del pedido a procesar: ", "\nError");

						if(BuscarPosicionPedidosPorID(pedidos, LEN, idPedido) != -1)
						{
							procesarPedidoOK = ProcesarPedido(pedidos, LEN, idPedido);

							if(procesarPedidoOK == 0)
							{
								printf("\nEl pedido %d fue procesado correctamente.", idPedido);

							}else if(procesarPedidoOK == -1)
							{
								printf("\nError, el pedido %d ya se encontraba procesado.", idPedido);

							}else
							{
								printf("\nError al procesar el pedido.");
							}

						}else
						{
							printf("\nNo hay pedidos activos con el ID %d.", idPedido);
						}
					}
					else
					{
						printf("\nNo hay pedidos pendientes en el sistema.");
					}
					break;
				case 6:
					if(HayCliente(clientes, TAM))
					{
						if(MostrarClientesConPedidosPendientes(clientes, TAM, pedidos, LEN, localidades, LARGO) == -1)
						{
							printf("\nError al mostrar la lista de clientes");
						}
					}
					else
					{
						printf("\nNo hay clientes cargados en el sistema.");
					}
					break;
				case 7:
					if(HayPedidoPendiente(pedidos, LEN))
					{

						if(MostrarPedidosPendientesYDatosCliente(clientes, TAM, pedidos, LEN,localidades, LARGO) == -1)
						{
							printf("\nError al mostrar la lista de pedidos");
						}
					}
					else
					{
						printf("\nNo hay pedidos pendientes cargados en el sistema.");
					}
					break;
				case 8:
					if(HayPedidoCompletado(pedidos, LEN))
					{
						if(MostrarPedidosCompletadosYDatosCliente(clientes, TAM, pedidos, LEN,localidades, LARGO) == -1)
						{
							printf("\nError al mostrar la lista de pedidos");
						}
					}
					else
					{
						printf("\nNo hay pedidos procesados cargados en el sistema.");
					}
					break;
				case 9:
					if(HayPedidoPendiente(pedidos, LEN))
					{

						localidad = PedirLocalidad(localidades, LARGO, "\nIngrese el numero de una localidad de la lista: ", "\nError, ingrese un numero de la lista: ");

						if (localidad == -2)
						{
							printf("\nBusqueda cancelada");
							break;
						}

						totalLocalidadesOK = BuscarPendientesParaLocalidad(clientes, TAM, pedidos, LEN,localidades, LARGO, localidad);

						posLocalidad = BuscarPosicionLocalidadesPorID(localidades, LARGO, localidad);

						if(totalLocalidadesOK > 0)
						{

							printf("\nEl total de pedidos para %s es %d",localidades[posLocalidad].descripcion, totalLocalidadesOK);
						}
						else if(totalLocalidadesOK == -1)
						{
							printf("\nNo hay pedidos pendientes para %s", localidades[posLocalidad].descripcion);
						}
						else
						{
							printf("\nError en la busqueda");
						}
					}
					else
					{
						printf("\nNo hay pedidos pendientes cargados en el sistema.");
					}
					break;
				case 10:
					if(HayPedidoCompletado(pedidos, LEN))
					{
						promedioPP = CalcularPromedioPP(clientes, TAM, pedidos, LEN);

						if(promedioPP != -1)
						{
							printf("\nEl promedio de polipropileno reciclado por cliente es de %.2f", promedioPP);
						}
						else
						{
							printf("\nError en calcular el promedio");
						}
					}
					else
					{
						printf("\nNo hay pedidos procesados cargados en el sistema.");
					}
					break;
				case 11:
					if (HayCliente(clientes, TAM) && HayPedidoPendiente(pedidos, LEN))
					{
						ClientesConMasPendientes(clientes, TAM, pedidos, LEN);
					}
					else
					{
						printf("\nNo se puede mostrar, no hay clientes o pedidos pendientes");
					}

					break;
				case 12:
					if (HayCliente(clientes, TAM) && HayPedidoCompletado(pedidos, LEN))
					{
						ClientesConMasCompletados(clientes, TAM, pedidos, LEN);
					}
					else
					{
						printf("\nNo se puede mostrar, no hay clientes o pedidos completados");
					}
					break;
				case 13:
					AltaLocalidad(localidades, LARGO);
					break;
				case 14:

					localidad = PedirLocalidad(localidades, LARGO, "\nIngrese el numero de la localidad que quiere dar de baja: ", "\nError, ingrese un numero de la lista: ");

					if (localidad == -2)
					{
						printf("\nSolicitud de baja cancelada.");
						break;
					}


					printf("\nConfirma la baja de la localidad? (Tambien se daran de baja los clientes y pedidos de esa localidad)");

					if(PedirSN("\nS/N: ", "\nError S/N: "))
					{
						posLocalidad = BuscarPosicionLocalidadesPorID(localidades, LARGO, localidad);

						bajaLocalidadOK = BajaLocalidad(clientes, TAM, pedidos, LEN, localidades, LARGO, localidad);

						if (bajaLocalidadOK != -1)
						{
							printf("\nLa localidad %s se dio de baja exitosamente.", localidades[posLocalidad].descripcion);
						}
						else
						{
							printf("\nError al realizar la baja.");
						}
					}
					else
					{
						printf("\nSolicitud de baja cancelada.");
					}

					break;
				case 15:
					if (HayLocalidad(localidades, LARGO))
					{
						localidad = PedirLocalidad(localidades, LARGO, "\nIngrese el numero de la localidad que quiere dar de baja: ", "\nError, ingrese un numero de la lista: ");

						if (localidad == -2)
						{
							printf("\nSolicitud de modificacion cancelada.");
							break;
						}

						if (ModificarLocalidad(localidades, LARGO, localidad) != -1)
						{
							printf ("\nModificacion Exitosa");
						}
						else
						{
							printf("\nError en la modificacion");
						}
					}
					else
					{
						printf("\nError, no hay localidades cargadas.");
					}
					break;
			}

		}while(opcion != 0);

		puts("\nPrograma finalizado.");


	return EXIT_SUCCESS;
}
