
+++ A FAIRE ++++

- Il y a un fichier de description de la scene. - OK

- Le fichier est en XML, ou en tout cas dispose d'une structure spéciale, d'une hiérarchie.. - OK

- Vos objets ne tombent jamais dans le noir total. - OK

- Si la lumiere d'ambiance est pas en dur dans le code mais reglable dans le fichier de conf. - OK

- On peut decouper basiquement les objets selon les axes x,y,z - OK

- Perturbation de la normale : genre avec un sinus, ca donne l'impression d'avoir des vaguelettes

- Perturbation de la couleur : un damier - OK
 
- Perturbation de la couleur : un algo un peu plus complique pour changer la couleur de l'objet
 
- Perturbation de la couleur : un algo super complexe, genre bruit de Perlin

- Reflexion marche, on a bien un effet mirroir - OK

- On peut changer le % de reflexion (c'est pas du tout ou rien) - OK

- La transparence fonctionne, on voit au travers - OK

- L'indice de refraction fonctionne (au besoin demander a voir la formule de Descartes dans le code) - OK

- On peut changer le % de transparence - OK

- Selon la transparence d'un objet, est-ce que son ombre s'éclaircit/s'assombrit ? - OK

- On peut appliquer une texture sur au moins un des 4 objets - OK

- On peut appliquer une texture sur les 4 objets - OK

- On peut etirer (ou le contraire) une texture sur un objet - OK

- On peut decaler une texture sur un objet - OK

- Utilisation d'une lib autre que la minilibX et ses xpm pour charger les textures (jpeg, png, ...)
 
- La texture sert a modifier la normale d'un objet (du bump mapping en gros)

- On peut définir un objet composé d'autres objets : verre

- On peut définir un objet composé d'autres objets : cube
 
- Et il est possible de definir le meme objet composé mais a des positions et avec des orientations diverses

- Antialiasing - OK

- Effet Cartoon - OK

- Motion blur - OK

- Sepia ou autre filtre de couleur - OK
 
- Stereoscopie simple

- Calcul multi thread - OK

- C'est PARTICULIEREMENT rapide comme rendu - OK

- Sauvegarde de l'image integree au RT - OK

- Il y a une interface sommaire - OK

- Il y a une interface chiadee - OK

- On peut parametrer plusieurs rendus automatiquement avec des changements d'un rendu a l'autre

- On peut generer automatiquement des objets pour une scene : un torre realise avec tout plein de spheres

- Une sequence video realisee avec votre RT !

- Fichiers modelers : vous importez les fichiers pov ou 3ds - OK

- D'autres trucs delirants - OK

- C'est beau ? - tres beau 




+++ A AJOUTER AU PARSER (dans l'ordre de priorité) +++

- Lumière ambiante :
Int entre 0 et 100 à mettre dans t_libx->ambient - OK

- Damier
2 couleurs + une longueur- OK

- Seconde texture dans les objets, norm_texture - OK

- Decalage texture (2 int) - OK

- Etirage texture (2 int) - OK

- Effet ondulé

- Objet cube
un point, un vecteur, une taille ?

- Objet verre
un point, un vecteur, une taille ?



