camera
{
	location <0,0,0> // la position de l'observateur
	look_at <1000,0,0>  // le point de vue
}

sphere { <5000,-15000,0>, 10000 // coord centre et rayon
         pigment { color rgb <1,0,0> }
         texture { soleil }
}

sphere { <5000,-1700,0>, 80 // coord centre et rayon
         pigment { color rgb <1,0,0> }
         texture { mercure }
}

sphere { <5000,-1300,0>, 100 // coord centre et rayon
         pigment { color rgb <1,0,0> }
         texture { venus }
}

sphere { <5000,-900,0>, 120 // coord centre et rayon
         pigment { color rgb <1,0,0> }
         texture { terre }
}

sphere { <5000,-500,0>, 90 // coord centre et rayon
         pigment { color rgb <1,0,0> }
         texture { mars }
}

sphere { <5000,200,0>, 250 // coord centre et rayon
         pigment { color rgb <1,0,0> }
         texture { jupiter }
}

sphere { <5000,1000,0>, 210 // coord centre et rayon
         pigment { color rgb <1,0,0> }
         texture { saturn }
}

sphere { <5000,1700,0>, 150 // coord centre et rayon
         pigment { color rgb <1,0,0> }
         texture { uranus }
}

sphere { <5000,2500,0>, 150 // coord centre et rayon
         pigment { color rgb <1,0,0> }
         texture { neptune }
}
