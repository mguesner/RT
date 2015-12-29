camera
{
   location <0,0,0> // la position de l'observateur
   look_at <0,0,1000>  // le point de vue
   //right x*image_width/image_height  // aspect ratio
   //angle 45 // l'angle de la caméra
   ambient_light 0.10 //lumiere ambiant
}

light_source { <0,-500,3500>
      color rgb<1,1,1>
}

light_source { <0,500,3500>
      color rgb<1,1,1>
}


sphere { <0,-500,1300>, 200 // coord centre et rayon
         pigment { color rgb <1,0,0> }
          finish {
            transparence 0.5
            refraction 1.0
          }
}

sphere { <0,500,1300>, 200 // coord centre et rayon
         pigment { color rgb <0,0,1> }
          finish {
            transparence 0.5
            refraction 1.0
          }
}

sphere { <300,0,1300>, 200 // coord centre et rayon
         pigment { color rgb <1,1,1> }
          finish {
            transparence 1.0
            refraction 1.0
          }
}

sphere { <-1000,300,4000>, 200 // coord centre et rayon
         pigment { color rgb <1,0,1> }
          finish {specular 1}
}

sphere { <-1000,-300,4000>, 200 // coord centre et rayon
         pigment { color rgb <0,1,1> }
          finish {specular 1}
}


plane { <1,0,0>,1000 // plane mur sol
         pigment { color rgb <0.9,1,0.9> }
}

plane { <-1,0,0>,1000 // plane mur plafond
         pigment { color rgb <0.9,1,0.9> }
}



plane { <0,0,1>,10000 // plane derriere
         pigment { color rgb <0.5,1,0.5> }
}

plane { <0,1,0>,1000 // plane mur gauche
         pigment { color rgb <1,0.9,0.9> }
}

plane { <0,-1,0>,1000 // plane mur droit
         pigment { color rgb <1,0.9,0.9> }
}
