#define CANTIDAD_EMPLEADOS 1000
#define CANTIDAD_SECTORES 3
#define VACIO 0
#define OCUPADO 1

typedef struct
{
    int id;
    int status;
    char name[51];
    char lastName[51];
    int sector;
    float salario;
}sGhost;

typedef struct
{
    int id;
    char descripcion[50];
}sGhostDos;

int initArrayStruct(sGhost *Ghost,int sizeGhost);
int buscarLugarLibre(sGhost *Ghost,int sizeGhost);
sGhostDos obtenerGhostDos(sGhostDos *GhostDos, int sizeGhostDos, sGhost *Ghost);
int addGhost(sGhost *Ghost,int sizeGhost,sGhostDos *GhostDos,int cantGhostDos,int id);
int mostrarUnGhost(sGhost unGhost,sGhostDos *GhostDos, int sizeGhostDos);
int imprimirTodosLosGhosts(sGhost *Ghost, int sizeGhost,sGhostDos *GhostDos,int sizeGhostDos);
int buscarGhostPorId(sGhost *Ghost, int sizeGhost, sGhostDos *GhostDos, int sizeGhostDos);
void menuModificacionGhosts(sGhost *Ghost, int sizeGhost, sGhostDos *GhostDos, int sizeGhostDos);
int bajaGhostPorId(sGhost *Ghost, int sizeGhost, sGhostDos *GhostDos, int sizeGhostDos);
int ordenarGhosts(sGhost *Ghost,int sizeGhost);
float totalSalariosGhosts(sGhost *Ghost, int sizeGhost);
void salarioPromedioGhosts(sGhost *Ghost,int sizeGhost);
void menuReportes(sGhost *Ghost, int sizeGhost, sGhostDos *GhostDos, int sizeGhostDos);
void ghostHardcodeo(sGhost *Ghost, int sizeGhost);
