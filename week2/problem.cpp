#include <iostream>
#include <cmath>

// Write a Program to calculate surface area, volume and mass of objects using cylindrical geometry formulae.
//
// Identify the inputs, outputs and units. Run the program with some sample data from the Web to confirm your algorithm
//
// Develop the program to compute the mass of the cylinders using a variety of densities (e.g. of precious metals), (e.g. the density of gold is 19.32 g/cm cubed). Ascertain the order (in kg) of the masses of three sample cylinders:
//
//     a gold cylinder of radius 9 and height 21cm
//     a platinum cylinder of r:11 and h:13 cm
//     a copper cylinder of r:17 and h:13cm
//
// See the following links for helpful numbers:
// https://www.quora.com/How-do-you-find-volume-from-density-and-mass
// https://www.engineeringtoolbox.com/metal-alloys-densities-d_50.html
// https://www.wikihow.com/Sample/Volume-of-a-Cone-Diagram

const double GOLD = 19.32;
const double PLAT = 21.45;
const double COPP = 8.92;
const double PI = 3.14159265359;

// vol is pi r^2 * h
// surface 2 * pi * r * h
// mass = vol * density

double getmass(double density, double height, double radius) {
  double nmass = 0.0;

  double volume = PI * pow(radius,2) * height;
  // double surface = 2 * PI * radius * height;
  nmass = volume * density / 1000;

  return nmass;
}

int main() {
  while (1) {
    double height;
    double radius;
    double mass;
    char material = 'l';

    std::cout << "Radius: ";
    std::cin >> radius;
    std::cout << "\n";

    std::cout << "Height: ";
    std::cin >> height;
    std:: cout << "\n";


    bool loop = 1;
    while (loop) {
      std::cout << "Material, (g), (p), (c): ";
      std::cin >> material;
      std::cout << "\n";
      std::cout << material << "\n";
      if (material != 'g' || material != 'p' || material != 'c') {
        loop = 0;
      }
    }

    switch(material) {
      case 'g': {
        mass = GOLD;
        break;
      }
      case 'c': {
        mass = COPP;
        break;
      }
      case 'p': {
        mass = PLAT;
        break;
      }
    }

    std::cout << getmass(mass, height, radius) << "\n";

  }
  return 0;
}
