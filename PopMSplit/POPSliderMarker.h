//
//  POPSliderMarker.h
//  PopMSplit
//
//  Created by Kevin Scardina on 4/27/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <QTKit/QTKit.h>

@interface POPSliderMarker : NSObject

@property NSButton* button;
@property QTTime qtMark;
@property NSSlider* slider;

- (void)create:(NSButton*)btn slider:(NSSlider*)sldr timeScale:(long)tscale;
- (NSString*)getMarkAsString;

@end
