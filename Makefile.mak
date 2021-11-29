CPP    = g++
WINDRES= windres
RM     = rm -f
OBJS   = polialfabetica.o \
         main.o \
         enigma.o \
         criptografia.o \
         CifraDeUsoUnico.o \
         CifraDeTransposicaoDeColunas.o \
         CifraDeCesar.o \
         AppResource.res

LIBS   =
CFLAGS =

.PHONY: Encriptacao.exe clean clean-after

all: Encriptacao.exe

clean:
	$(RM) $(OBJS) Encriptacao.exe

clean-after:
	$(RM) $(OBJS)

Encriptacao.exe: $(OBJS)
	$(CPP) -Wall -s -o $@ $(OBJS) $(LIBS)

polialfabetica.o: polialfabetica.cpp Polialfabetica.h
	$(CPP) -Wall -s -c $< -o $@ $(CFLAGS)

main.o: main.cpp CifraDeCesar.cpp criptografia.cpp Polialfabetica.cpp CifraDeUsoUnico.cpp CifraDeTransposicaoDeColunas.cpp enigma.cpp CifraDeCesar.cpp criptografia.cpp Polialfabetica.cpp CifraDeUsoUnico.cpp CifraDeTransposicaoDeColunas.cpp enigma.cpp
	$(CPP) -Wall -s -c $< -o $@ $(CFLAGS)

enigma.o: enigma.cpp criptografia.h enigma.h
	$(CPP) -Wall -s -c $< -o $@ $(CFLAGS)

criptografia.o: criptografia.cpp criptografia.h
	$(CPP) -Wall -s -c $< -o $@ $(CFLAGS)

CifraDeUsoUnico.o: CifraDeUsoUnico.cpp criptografia.h CifraDeUsoUnico.h
	$(CPP) -Wall -s -c $< -o $@ $(CFLAGS)

CifraDeTransposicaoDeColunas.o: CifraDeTransposicaoDeColunas.cpp CifraDeTransposicaoDeColunas.h
	$(CPP) -Wall -s -c $< -o $@ $(CFLAGS)

CifraDeCesar.o: CifraDeCesar.cpp CifraDeCesar.h
	$(CPP) -Wall -s -c $< -o $@ $(CFLAGS)

AppResource.res: AppResource.rc
	$(WINDRES) -i AppResource.rc -J rc -o AppResource.res -O coff

