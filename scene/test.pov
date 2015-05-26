camera
{
   location <0,0,0> // la position de l'observateur
   look_at <1000,0,0>  // le point de vue
   //right x*image_width/image_height  // aspect ratio
   //angle 45 // l'angle de la caméra
}

light_source { <0,0,0>
		color rgb<1,1,1>
}

plane { <-1,0,0>,2500 // coord centre et rayon
         pigment { color rgb <1,1,1> }
}

sphere { <-2000,0,0>, 100 // coord centre et rayon
         pigment { color rgb <1,0,1> }
}
