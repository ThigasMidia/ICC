# PROGRAMA
    PROG = resolveEDO
    OBJS = resolveEDO.o edo.o utils.o edo_aux.o

# Compilador
    CC = gcc

# Acrescentar onde apropriado as opções para incluir uso da biblioteca LIKWID
    CFLAGS = -O0 -g -DLIKWID_PERFMON -I${LIKWID_INCLUDE}
    LFLAGS = -lm -L${LIKWID_LIB} -llikwid

# Lista de arquivos para distribuição. Acrescentar mais arquivos se necessário.
DISTFILES = *.c *.h LEIAME* Makefile edo.dat 
DISTDIR = ${USER}

.PHONY: clean purge dist all

%.o: %.c %.h utils.h
	$(CC) -c $(CFLAGS) -o $@ $<

all: $(PROG)

$(PROG): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)

clean:
	@echo "Limpando sujeira ..."
	@rm -f *~ *.bak

purge:  clean
	@echo "Limpando tudo ..."
	@rm -f $(PROG) $(OBJS) core a.out $(DISTDIR) $(DISTDIR).tgz

dist: purge
	@echo "Gerando arquivo de distribuição ($(DISTDIR).tgz) ..."
	@ln -s . $(DISTDIR)
	@tar -chvzf $(DISTDIR).tgz $(addprefix ./$(DISTDIR)/, $(DISTFILES))
	@rm -f $(DISTDIR)
