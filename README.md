# The Winamp Remote Control

## Overview

Consists of a plugin that is compatible with the winamp 2.5.x API, along with a client, allowing multiple users to share a centralised Winamp server.

Built using c++ Builder 5 onwards and uses MS-RPC for the communication mechanismm.

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

## Plan

 The game plan is to restore a working version for now, with my version of c++Builder5.
 Given it's been so long since the old version worked, backwards compatbility is not going to be an issue.
 After that: there was a linux client and there could be some more X platform code in there without too much effort
 - it's not, fundamentally a big project.
 Getting the right options to MIDL to prevent disaster - that's another story.

