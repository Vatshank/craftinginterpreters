//
// Created by Chaturvedi, Vatshank on 10/16/22.
//

#include "common.h"
#include "chunk.h"
#include "debug.h"
#include "vm.h"

int main(int argc, const char* argv[]) {
    initVM();

    Chunk chunk;
    initChunk(&chunk);

    int constant = addConstant(&chunk, 1.2);
    writeChunk(&chunk, OP_CONSTANT, 33);
    writeChunk(&chunk, constant, 33);

    constant = addConstant(&chunk, 3.4);
    writeChunk(&chunk, OP_CONSTANT, 33);
    writeChunk(&chunk, constant, 33);

    writeChunk(&chunk, OP_ADD, 33);

    constant = addConstant(&chunk, 5.6);
    writeChunk(&chunk, OP_CONSTANT, 33);
    writeChunk(&chunk, constant, 33);

    writeChunk(&chunk, OP_DIVIDE, 33);

    writeChunk(&chunk, OP_NEGATE, 33);

    writeChunk(&chunk, OP_RETURN, 34);

    disassembleChunk(&chunk, "test chunk");

    interpret(&chunk);

    freeVM();
    freeChunk(&chunk);
    return 0;
}