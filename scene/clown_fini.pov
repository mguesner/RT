camera
{
    location <-500,0,-500> // la position de l'observateur
    look_at <1000,0,0>  // le point de vue
}

light_source { <300, 100,0>
        color rgb<1,1,1>
}

sphere { <1320,0,200>, 30 // coord centre et rayon
         pigment { color rgb <1,0,0> }
         finish {specular 1}
}

sphere { <1500,0,200>, 180 // coord centre et rayon
         pigment { color rgb <1,0.8,0.75> }
         finish {specular 1}
}

sphere { <1380,60,130>, 45 // coord centre et rayon
         pigment { color rgb <1,1,1> }
}

sphere { <1380,-60,130>, 45 // coord centre et rayon
         pigment { color rgb <1,1,1> }
}

cone_42 { <1500,0,-200>, <0,0,1>, 0.4 // coord, direction, rayon
         pigment { color rgb <1,0,0> }
         texture { damier2 }
         end 300 600
}

cylinder_42 { <1320,70,0>, <0,0,1>, 10 // coord, direction, rayon
         pigment { color rgb <0,0,1> }
         end 590 620
}

cylinder_42 { <1320,-70,0>, <0,0,1>, 10 // coord, direction, rayon
         pigment { color rgb <0,0,1> }
         end 590 620
}
