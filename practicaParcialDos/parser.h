#ifndef parser_H_INCLUDED
#define parser_H_INCLUDED
//int parser_cachorrosParser(FILE* pFile, LinkedList* listaCachorros);
int parser_parserCachorros(char* fileName, LinkedList* listaCachorros);
int saveArchivo(char* path , LinkedList* listaCachorros);
#endif // parser_H_INCLUDED
