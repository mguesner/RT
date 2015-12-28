camera
{
   location <-300,1000,-2000> // la position de l'observateur
   look_at <-300,1000,1000>  // le point de vue
   ambient_light 0.5//lumiere ambiant
}

light_source { <-300,250,1000>
      color rgb <1,1,1>
}

plane { <1,0,0>, 1000 // coord centre et rayon
         pigment { color rgb <1,1,1> }
         texture { name brickwork
         etir <0.2,0.2,0> 
         offset <100,100,0>
         }
}

plane { <0,-1,0>, 2000 // coord centre et rayon
         pigment { color rgb <1,1,0.6> }
         perlin 20
}

plane { <0,0,1>, -10000 // coord centre et rayon
         pigment { color rgb <1,1,1> }
         damier { color rgb <0,1,0> long 200 }
}

sphere { <0,500,1000>, 200 // coord centre et rayon
         pigment { color rgb <1,0.5,1> }
         damier { color rgb <1,0,1> long 200 }
}

sphere { <0,800,500>, 50 // coord centre et rayon
         pigment { color rgb <1,0.5,1> }
         finish {
            transparence 0.8
            refraction 1.0
          }
}