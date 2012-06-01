//
//  POPAppDelegate.h
//  PopMSplit
//
//  Created by Kevin Scardina on 4/27/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <QTKit/QTKit.h>

@interface POPAppDelegate : NSObject <NSApplicationDelegate>
{
    NSMutableArray *splitDS;
    NSURL* url;
    bool splitting;
    //NSPipe *ffmpegpipe;
    NSTask *ffmpeg;
    NSMutableArray *tasks;
    int tasksIdx;
    NSMutableArray *tPipes;
    NSString* allSplitInfo;
    NSString* outputDir;
    NSString* outputMask;
    
}

@property(retain) QTMovie *movie;
@property(readwrite) BOOL playing;
@property(readwrite) float rate;
@property(readwrite) NSThread* splitInfoThread;
@property(readwrite) NSTimer* slideTimer;
@property (assign) IBOutlet NSWindow *window;
@property (weak) IBOutlet NSButton *playBtn;
@property (weak) IBOutlet NSSlider *seekSlider;
@property (weak) IBOutlet QTMovieView *movieView;
@property (weak) IBOutlet NSTextFieldCell *splitInfo;
@property (weak) IBOutlet NSTextField *infoLabel;
@property (weak) IBOutlet NSPopUpButtonCell *marks;
@property (unsafe_unretained) IBOutlet NSWindow *splitWnd;
@property (weak) IBOutlet NSTableView *splitTable;
@property (weak) IBOutlet NSButton *splitStartStopBtn;
@property (weak) IBOutlet NSButton *closeSplitBtn;
@property (unsafe_unretained) IBOutlet NSWindow *aboutWnd;
@property (unsafe_unretained) IBOutlet NSWindow *prefWnd;
@property (weak) IBOutlet NSProgressIndicator *splitProgIndicator;
@property (weak) IBOutlet NSButton *audioCB;
@property (weak) IBOutlet NSButton *videoCB;
@property (unsafe_unretained) IBOutlet NSTextView *splitOutput;
@property (weak) IBOutlet NSButtonCell *convertCB;
@property (weak) IBOutlet NSPopUpButtonCell *convertToBtn;
@property (weak) IBOutlet NSButton *outputDirectoryBtn;
@property (weak) IBOutlet NSTextField *outputFilenameMaskField;
@property (weak) IBOutlet NSMatrix *outputDirectoryRB;
@property (weak) IBOutlet NSTextField *outputDirectoryText;

- (IBAction)selectSource:(id)sender;
- (IBAction)split:(id)sender;
- (IBAction)play:(id)sender;
- (IBAction)stop:(id)sender;
- (IBAction)back:(id)sender;
- (IBAction)forward:(id)sender;
- (IBAction)addSplit:(id)sender;
- (IBAction)removeSplit:(id)sender;
- (IBAction)seek:(id)sender;
- (IBAction)about:(id)sender;
- (IBAction)gotoMark:(id)sender;
- (IBAction)closeSplitWnd:(id)sender;
- (IBAction)splitStartStop:(id)sender;
- (IBAction)aboutCloseBtnClick:(id)sender;
- (IBAction)prefWndShow:(id)sender;
- (IBAction)prefCloseBtnClick:(id)sender;
- (IBAction)removeSegBtnClick:(id)sender;
- (IBAction)convertToClick:(id)sender;
- (IBAction)outputDirectoryBtnClick:(id)sender;
- (IBAction)outputDirectoryRBChange:(id)sender;
- (IBAction)helpClick:(id)sender;

- (void)refreshSplitInfo:(NSPipe*)pipe;
- (void)startSplitInfoThread:(NSPipe*)pipe;
- (void)refreshSlider:(NSTimer*)theTimer;
- (void)startSliderTimer;
- (void)stopSliderTimer;
- (void)taskExited:(NSNotification*)note;

- (int)numberOfRowsInTableView:(NSTableView *)aTableView;
- (id)tableView:(NSTableView*)aTableView 
    objectValueForTableColumn:(NSTableColumn*)aTableColumn 
            row:(NSInteger)rowIndex;
- (void)tableView:(NSTableView*)aTableView 
   setObjectValue:(id)anObject 
   forTableColumn:(NSTableColumn *)aTableColumn 
              row:(NSInteger)rowIndex;

@end
