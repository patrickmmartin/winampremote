# The Winamp Remote Control

## Overview

Consists of a plugin that is compatible with the winamp 2.5.x API, along with a client, allowing multiple users to share a centralised Winamp server.

Built using c++ Builder 5 onwards and uses MS-RPC (over tcp) for the communication mechanismm.

A linux client was created which worked fine, linked against the DCE-RPC runtime.

This project was active for a couple of years around 2000-2002 and produced a number of revisions that were externally released.

These code releases and the other related assets have been poured into git.

The project appears to have been quite popular for a while.

## Winamp Versions

It targets the Winamp API introduced in 2.5x API and implemented in 5.x.
 
## Features

Some features of note were

 * network remote control clients
 * ability to minimize to the tray as a clickable icon
 * pause / stop / play
 * EQ and volume
 * playlist import / management with our friends drag and drop
 * automated discovery of servers on the network
 * and much, much, more ...

## Security
 The final blow was the Windows XP Service Pack which locked down security for unauthenticated RPC endpoints.
 The original choice of transport was unauthenticated RPC over tcpip; something like named pipes transport allows
 basic authentication to be applied, and hence it seems (so far: touch wood) to work without requirements on current
 Windows revisions.

## Plan

 This is the archtypal pet project: for now I'll be happy to revisit some old friends from 12 years ago.
 The game plans are:
### short term 
* Bring the build process / tests / coding  up to date
* Produce a complete version that works on current Windows releases.
 Given it's been so long since the old version worked, backwards compatbility is not going to be an issue.


### medium term
* There was a linux client once for the tcp transport - reactivating this would be an interesting exercise                                                      

* As a parallel vein, creating a more transportable UI, such as in QT or HTML5 would be equally interesting 

