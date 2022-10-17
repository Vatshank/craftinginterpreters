//
// Created by Chaturvedi, Vatshank on 10/16/22.
//

#include "common.h"
#include "chunk.h"
#include "debug.h"

int main(int argc, const char* argv[]) {
    Chunk chunk;
    initChunk(&chunk);
    int constant = addConstant(&chunk, 1.2);
    writeChunk(&chunk, OP_CONSTANT, 33);
    writeChunk(&chunk, constant, 33);

    writeChunk(&chunk, OP_RETURN, 34);

    disassembleChunk(&chunk, "test chunk");
    freeChunk(&chunk);
    return 0;
}