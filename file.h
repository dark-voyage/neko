//
// Created by Sokhibjon Orzikulov on 13/02/23.
//

#ifndef NEKO_FILE_H
#define NEKO_FILE_H

#define CHUNK_SIZE 1024 // read 1024 bytes at a times

int file_exists(const char *filename);
int read_file(const char *filename);

#endif//NEKO_FILE_H
