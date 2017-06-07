////////////////////////////////////////////////////////////////////////////////
Fractal = complex figure with infinity of details. Cannot be describe with usual geometry.

////////////////////////////////////////////////////////////////////////////////
Complex Numbers = Real nb + Imaginary nb
z a complex nb, x a real, y a imaginary nb
z = x + yi
with i^2 = -1

Complex nb could be used to represent points in a plan: the real = x-axis
imagi = y-axis
z = x + yi correspond to the point M (x;y)
the distance between O and M correspond to the module of z --> |z| <=> sqr(x^2 + y^2)

////////////////////////////////////////////////////////////////////////////////
Mathematical series:
a serie = familly of elements indexed by natural integers.
eample with index n = 3 --> Un = 5n + 1 <=> U3 = 5 * 3 + 1

other way to define a serie: recurrence
we define the first terme of the serie then a reccurence formula will allow
to calculate a term in function of the previous.
ex: U0 = 1        recurrence formula: Un+1 = 3Un - 1
--> U2 = 3U1 - 1 = 3 * (3U0 - 1) - 1 = 5
////////////////////////////////////////////////////////////////////////////////

MANDELBROT ensemble:
the formula that defines the ensemble de Mandelbrot: 
ensemble des points du plan complexe pouur la suite cZn+1 = (Zn)^2 + cZ0 = 0
avec pour condition ne tends pas vers infini en module.

--> on regarde chaque point de limage et on regarde si la suite tends vers
infini en module. (si le module de Zn pour n tres grand se rapproche de infini)
--> trop complexe pour ordi donc on test si le module de Zn depasse 2
a un moment. si il depasse pas alors il fait parti de la fractale.

Pour savoir si il depasse ou pas 2, on va regarder pour un n suffisament grand
et penser raisonnablement qu'il depasse pas. 
C'est le rang (nb iterations) que l'on va choisir et qui va impacter
la qualitee finale.
trop de points --> trop nette. et inverse.

////////////////////////////////////////////////////////////////////////////////
Algorithme:

definir iteration_max

function	pour chaque point dans le plan (int x,int y)
{
	j = 0
	z = 0
	c = x + iy

	while (module z < 2 && j < iteration_max)
	{
		z = z*z + c
		j++
	}

	if (j = iteration_max)
		dessiner le pixel correspondant au point (x, y)
}

////////////////////////////////////////////////////////////////////////////////
Simple mais il faut implementer le cote nb complexe dans le code.

Zr pour partie reelle
Zi pour imaginaire

z = z * z + c 
	= (Zr + Zi * i)^2 + (Cr + Ci * i) = (Zr^2 - Zi^2 + Cr) + (2 * Zr * Zi + Ci) * i

Zr = Zr^2 - Zi^2 + Cr
Zi = 2 * Zr * Zi + Ci

Au lieu de calculer le module de Z et comparer a 2 on va calculer le carre de ses
composantes et comparer ce resultat a 4

sqrt(Zr^2 + Zi^2) < 2
	<=> Zr&2 + Zi^2 < 4

Algo:

definir iteration_max

function	pour chaque point dans le plan (int x,int y)
{
	c_r = x
	c_i = y
	z_r = 0
	z_i = 0
	j = 0

	while ((z_r * z_r + z_i * z_i) < 4  && j < iteration_max)
	{
		tmp = z_r
		z_r = z_r * z_r - z_i * z_i + c_r
		z_i = 2 * z_i * tmp + c_i
		j++
	}

	if (j = iteration_max)
		dessiner le pixel correspondant au point (x, y)
}
////////////////////////////////////////////////////////////////////////////////

Le pb est que on va utiliser une image pour dessiner la fractale, ici on utilise
un plan x y. on va faire correspondre les deux.
Il existe 2 techniques pour faire correspondre le plan avec image utilisee.

METHODE: on va definir la zone a dessiner et une valeur de zoom. on calcule ensuite
la taille de image a partir de ces infos
Mandelbrot tjs compris entre abscisse(-2.1 et 0.6) ordonnees(-1.2 et 1.2)

On definit la zone qu'on dessine, ici fractale entiere
x1 = -2.1
x2 = 0.6
y1 = -1.2
y2 = 1.2

calcul taille image
definir image_x = (x2 - x1) * zoom
definir image_y = (y2 - y1) * zoom

x = 0
while (x < image_x par pas de 1)
{
	y = 0
	while (y < image_y par pas de 1)
	{
		c_r = x / zoom + x1
		c_i = y / zoom + y1
		z_r = 0
		z_i = 0
		i = 0
		y++
	}
	
	while (z_r * z_r + z_i * z_i) < 4 && j < iterations_max
	{
		tmp = z_r
		z_r = z_r * z_r - z_i * z_i + c_r
		z_i = 2 * z_i * tmp + c_i
		j++
	}

	if (j = iteration_max)
		dessiner pixel correspondant au point (x;y)
}
bien car on defini soit meme zoom que on veut
mal car on sait pas taille et possible d'avoir truc gigantesque et ca ram a fond
////////////////////////////////////////////////////////////////////////////////

METHODE: definir la zone a dessiner et definir la taille de image
zoom sera calcule en fonction de ces valeurs.

x1 = -2.1
x2 = 0.6
y1 = -1.2
y2 = 1.2

image_x = 270
image_y = 240
iteration_max = 50

zoom_x = image_x / (x2 - x1)
zoom_y = image_y / (y2 - y1)

x = 0
while (x < image_x)
{
	y = 0
	while (y < image_y)
	{
		c_r = x / zoom_x + x1
		c_i = y / zoom_y + y1
		z_r = 0
		z_i = 0
		y++
	}

	while (z_r * z_r + z_i * z_i) < 4 && j < iterations_max
	{
		tmp = z_r
		z_r = z_r * z_r - z_i * z_i + c_r
		z_i = 2 * z_i * tmp + c_i
		j++
	}

	if (j = iteration_max)
		dessiner pixel correspondant au point (x;y)

	x++
}

avantage: on a image taille que on veut
incovenient: disproportion ultime
Methode 1 mieux.
////////////////////////////////////////////////////////////////////////////////
COULEUR:
il suffit d'assigner une couleur en fonction du nombre iterations quil y a eut
exemple: fractale entouree en bleue,+ il y a iteration + bleu est clair

x1 = -2.1
x2 = 0.6
y1 = -1.2
y2 = 1.2
zoom = 100   pour une distance de 1 on a 100 pixels sur l'image.
iteration_max = 50
image_x = (x2 - x1) * zoom
image_y = (y2 - y1) * zoom

x - 0
while (x < x_image)
{
	y = 0
	while (y < y_image)
	{
		c_r = x / zoom + x1
		c_i = y / zoom + y1
		z_r = 0
		z_i = 0
	}
	j = 0
	while (z_r * z__r + z_i * z_i) < 4  && j < iteration_max
	{
		tmp = z_r
		z_r = z_r * z_r - z_i * z_i + c_r
		z_i = 2 * z_i * tmp + c_i
		j++
	}
	if (j == iterations_max)
		dessiner le pixel en noir
	else
		dessiner avec couleur rgb(0, 0, j * 255 / iteration_max)
}
mettre des degrades de couleurs c'est plus joli pas juste 2 couleurs.

////////////////////////////////////////////////////////////////////////////////
ZOOM:
il faut faire varier les parametres. Il faut augmenter le zoom mais si on
augmente que le zoom c'est pas cool

COORD DU PLAN COMPLEXE
x1 = limite gauche de image (x2 limite droite)
y1 = limite haut image (y2 limite bas)
si on augmente x1 image sera plus petite vers la droite

NB ITERATIONS MAX
plus on zoom plus il faut etre precis
ex: si je zoom en haut a droite il faudra doubler le zoom, augmenter x1,
diminuer y2 et augmenter un peu iterations_max

si vous voulez zoomer sur un point precis il faut definir simplement
x1 = x - h
x2 = x + h
y1 = y - h
y2 = y - h
avec h une valeur de votre choix (plus h petit plus vous zoomerez sur ce point)
faire correspondre zoom et iterations avec evidement.

