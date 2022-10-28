CFLAGS=-s
head: v7kill
v7kill:
	$(CC) -o v7kill v7kill.c
install:
	install -s v7kill $(DESTDIR)/usr/local/bin
clean:
	rm -rf v7kill
