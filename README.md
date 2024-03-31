# Multivariate Threshold Ring Signature Scheme Keygen Algorithm

*disclaimer: this implementation is a part of ŠVOČ research paper and final thesis

## Table of Contents
1. [Overview](#overview)
2. [Compilation](#compilation)
3. [Usage](#usage)
4. [Project structure](#project-structure)
5. [License](#license)

## Compilation


## Overview
This project presents an implementation of a random number generator (RNG) designed for the Arduino Nano microcontroller using C++.
The implemented KeyGen algorithm is a part of multivariate threshold ring signature scheme proposed in https://doi.org/10.1016/j.csi.2020.103489.
The arduino generator is used for generating random entropy source for seeding HMAC DRNG implemented based on publication
NIST SP-800 90A. The output of generator is used to generate random private and public key and output them to coressponding files.

## Usage
1. Connect arduino with implemented generator code
2. 

## Project Structure
- ARD - Contains C code implemented on arduino
- gen - Implementation of keygen algorithm
- HMAC_DRBG - HMAC DRBG implementation where entropy is taken from hardware device
- NTL - ntl library headers

## License