CC = clang++
CFLAGS = -g -Wall
INCLUDES = -I/usr/local/include
LFLAGS = -L/usr/local/lib
LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lm -lX11 -lpthread
OBJS = 	main.o game.o keyboard.o screen.o spritesheet.o spritesheets.o sprite.o \
		sprites.o tile.o grasstile.o voidtile.o tiles.o level.o randomlevel.o \
		entity.o mob.o player.o flowertile.o rocktile.o spawnlevel.o levels.o \
		tilecoord.o mouse.o projectile.o wizardprojectile.o levelentities.o \
		spawnfactory.o particle.o normalparticle.o animatedsprite.o dummy.o \
		chaser.o levelplayers.o vector2i.o node.o
HEADERS = 

test : $(OBJS)
	$(CC) $(CFLAGS) $(LFLAGS) $(LIBS) -o $(.CURDIR)/$(.PREFIX) $(.ALLSRC) 

$(OBJS) : $(.CURDIR)/$(.PREFIX).cc  
	$(CC) $(CFLAGS) $(INCLUDES) -c $(.CURDIR)/$(.PREFIX).cc -o $(.OBJDIR)/$(.PREFIX).o

.PHONY : clean 
clean :
	-rm *.o

.PHONY : cleanall 
cleanall :
	-rm $(.CURDIR)/test *.o
