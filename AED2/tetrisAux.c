// void leerPuntuacion(tDatos);

// void leerPuntuacion(tDatos usuario)
// {
//     archivoPuntuacion = fopen("dataPuntuacion.dat", "rb");

//     fread(&usuario, sizeof(tDatos), 1, archivoPuntuacion);

//     printf("Usuario: %s\n", usuario.nombre);

//     while (!feof(archivoPuntuacion))
//     {
//         printf("puntuacion: %d nombre: %s\n ", usuario.puntuacion, usuario.nombre);
//         fread(&usuario, sizeof(tDatos), 1, archivoPuntuacion);
//     }
//     fclose(archivoPuntuacion);
// }