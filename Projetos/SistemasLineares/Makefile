# PROGRAMA
    PROG = perfSL
    OBJS = utils.o SL_aux.o # acrescentar aqui outros módulos do programa

# Compilador
    CC     = gcc

# Acrescentar onde apropriado as opções para incluir uso da biblioteca LIKWID
    CFLAGS = -O0 -g
    LFLAGS = -lm

# Lista de arquivos para distribuição
DISTFILES = *.c *.h LEIAME* Makefile sistemas.dat
DISTDIR = ${USER}

.PHONY: all clean purge dist

%.o: %.c %.h utils.h 
	$(CC) -c $(CFLAGS) -o $@ $<

all: $(PROG)

$(PROG): % : %.o $(OBJS) 
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)

clean:
	@echo "Limpando sujeira ..."
	@rm -f *~ *.bak

purge:  clean
	@echo "Limpando tudo ..."
	@rm -f $(PROG) *.o core a.out $(DISTDIR) $(DISTDIR).tar

dist: purge
	@echo "Gerando arquivo de distribuição ($(DISTDIR).tar) ..."
	@ln -s . $(DISTDIR)
	@tar -cvf $(DISTDIR).tar $(addprefix ./$(DISTDIR)/, $(DISTFILES))
	@rm -f $(DISTDIR)
