camera
{
   location <0,0,0>
   look_at <1000,0,0>
}

light_source { <300, 100,0>
		color rgb<1,1,1>
}

plane { <-1,0,0>,5500 // coord centre et rayon
         pigment { color rgb <1,1,1> }
}

sphere { <2000,-600,-600>, 200 // coord centre et rayon
         pigment { color rgb <1,0,0> }
         finish {transparence 0.5}
}

sphere { <2000,0,-600>, 200 // coord centre et rayon
         pigment { color rgb <0,1,0> }
         finish {transparence 0.5}
}

sphere { <2000,600,-600>, 200 // coord centre et rayon
         pigment { color rgb <0,0,1> }
         finish {transparence 0.5}
}

sphere { <2000,-600,0>, 200 // coord centre et rayon
         pigment { color rgb <1,1,0> }
         finish {transparence 0.5}
}

sphere { <2000,0,0>, 200 // coord centre et rayon
         pigment { color rgb <1,0,1> }
         finish {transparence 0.5}
}

sphere { <2000,600,0>, 200 // coord centre et rayon
         pigment { color rgb <0,1,1> }
         finish {transparence 0.5}
}

sphere { <2000,-600,600>, 200 // coord centre et rayon
         pigment { color rgb <0.5,0.5,1> }
         finish {transparence 0.5}
}

sphere { <2000,0,600>, 200 // coord centre et rayon
         pigment { color rgb <1,0.5,1> }
         finish {transparence 0.5}
}

sphere { <2000,600,600>, 200 // coord centre et rayon
         pigment { color rgb <0.5,0.1,0.9> }
         finish {transparence 0.5}
}
