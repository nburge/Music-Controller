//
//  GeneradorEv.h
//  MusicController
//
//  Created by David Becerril Valle on 6/20/08.
//  Copyright 2008 DaveBV.es. All rights reserved.
//

#import <Cocoa/Cocoa.h>

#import "MidiEventOutput.h"
#import "WiiControls.h"
#import <WiiRemote/WiiRemote.h>
#import "OSCEventClass.h"

#define LONG_BUF 10

@interface GeneradorEv : NSObject {
	// Modo en el que se encuentra
	NSString *modoSTR ;
	unsigned short modo ;
  unsigned short modo_ant ;
	
	int contador ;
	// Valores del estado anterior
	unsigned char valorrotANT1 ;
	unsigned char valorincANT1 ;
	unsigned char valorrotANT2 ;
	unsigned char valorincANT2 ;
	unsigned char valorrotANT3 ;
	unsigned char valorincANT3 ;
	unsigned char valorrotANT4 ;
	unsigned char valorincANT4 ;
	
	BOOL variableA ; // Estado anterior botón A
	
	double umbral; // Umbral launch escena
	
	double acelex[LONG_BUF];
	double mediaacelx ;
	double aceley[LONG_BUF] ;
	double mediaacely ;
	double acelez[LONG_BUF] ;
	double mediaacelz ;
	double rollb[LONG_BUF] ;
	double mediarollb ;
	double pitchb[LONG_BUF] ;
	double mediapitchb ;
}

@property (readwrite,assign) NSString *modoSTR;
@property (readwrite,assign) unsigned short modo;
@property (readwrite,assign) unsigned short modo_ant;
//@property (readwrite,assign) double acelex;
@property (readwrite,assign) double mediaacelx;
//@property (readwrite,assign) double aceley;
@property (readwrite,assign) double mediaacely;
//@property (readwrite,assign) double acelez;
@property (readwrite,assign) double mediaacelz;
//@property (readwrite,assign) double rollb;
@property (readwrite,assign) double mediarollb;
//@property (readwrite,assign) double pitchb;
@property (readwrite,assign) double mediapitchb;

-(void)cambiaModo:(WiiControls *)_wiicontrols 
       conWiimote:(WiiRemote *)wiimote
        isPressed:(BOOL)apretado;

-(void)cambiaModo:(unsigned short)manualMode
       conWiimote:(WiiRemote *)wiimote;

-(void) manipular: (WiiControls *)_wiicontrols 
        mandarloA: (MidiEventOutput*)evts
        tipoBoton: (WiiButtonType)boton
        mandarOSC: (OSCEventClass*)oscObj;


-(void) manipularAcc:(WiiControls *)_wiicontrols 
           mandarloA: (MidiEventOutput*)evts
           mandarOSC: (OSCEventClass*)oscObj;


@end
