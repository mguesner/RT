il y a un fichier de description de la scene. -
Le fichier est en XML, ou en tout cas dispose d'une structure spéciale, d'une hiérarchie.. -
Vos objets ne tombent jamais dans le noir total. -
Si la lumiere d'ambiance est pas en dur dans le code mais reglable dans le fichier de conf.
on peut decouper basiquement les objets selon les axes x,y,z -
perturbation de la normale : genre avec un sinus, ca donne l'impression d'avoir des vaguelettes
perturbation de la couleur : un damier 
 perturbation de la couleur : un algo un peu plus complique pour changer la couleur de l'objet
 perturbation de la couleur : un algo super complexe, genre bruit de Perlin
 a reflexion marche, on a bien un effet mirroir -
 on peut changer le % de reflexion (c'est pas du tout ou rien) -
 a transparence fonctionne, on voit au travers -
 L'indice de refraction fonctionne (au besoin demander a voir la formule de Descartes dans le code) -
 on peut changer le % de transparence -
 Selon la transparence d'un objet, est-ce que son ombre s'éclaircit/s'assombrit ? -
 On peut appliquer une texture sur au moins un des 4 objets -
 On peut appliquer une texture sur les 4 objets -
  on peut etirer (ou le contraire) une texture sur un objet
  on peut decaler une texture sur un objet
  Utilisation d'une lib autre que la minilibX et ses xpm pour charger les textures (jpeg, png, ...)
 la texture sert a modifier la normale d'un objet (du bump mapping en gros)
 On peut définir un objet composé d'autres objets : verre
 On peut définir un objet composé d'autres objets : cube
 Et il est possible de definir le meme objet composé mais a des positions et avec des orientations diverses
 Antialiasing -
 effet Cartoon -
 motion blur -
 sepia ou autre filtre de couleur -
 stereoscopie simple
 calcul multi thread -
 c'est PARTICULIEREMENT rapide comme rendu -
 sauvegarde de l'image integree au RT
 il y a une interface sommaire -
 il y a une interface chiadee -
 On peut parametrer plusieurs rendus automatiquement avec des changements d'un rendu a l'autre
 On peut generer automatiquement des objets pour une scene : un torre realise avec tout plein de spheres
 une sequence video realisee avec votre RT !
 fichiers modelers : vous importez les fichiers pov ou 3ds -
 d'autres trucs delirants -
 C'est beau ? -