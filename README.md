In an attempt to learn C++ I created a program to simulate orbits of celestial bodies.

## Input

The program reads in a json file with the attributes of N bodies in the form of:

```json
{
  "bodies": [
    {
      "mass": int,  
      "radius": int,
      "pos_x": int,
      "pos_y": int,
      "vel_x": int,
      "vel_y": int,
      "drawline": bool
    }
],
  "stay_in_bounds": bool
}
```


