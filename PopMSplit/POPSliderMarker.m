//
//  POPSliderMarker.m
//  PopMSplit
//
//  Created by Kevin Scardina on 4/27/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "POPSliderMarker.h"

@implementation POPSliderMarker

@synthesize button;
@synthesize qtMark;
@synthesize slider;

- (void)create:(NSButton*)btn slider:(NSSlider*)sldr timeScale:(long)tscale
{
    [self setSlider:sldr];
    [self setQtMark:QTMakeTime((long)(long)[sldr floatValue], tscale)];
    NSLog([NSString stringWithFormat:@"x: %d; y: %d", [sldr rectOfTickMarkAtIndex:(NSInteger)([sldr floatValue]/[sldr maxValue])*100].origin.x, [sldr rectOfTickMarkAtIndex:(NSInteger)[sldr floatValue]/[sldr maxValue]].origin.y]);
    [self setButton:[btn ]];
    [[self button] setFrameOrigin:NSMakePoint(100, 10)];//[sldr rectOfTickMarkAtIndex:(NSInteger)[sldr floatValue]/[sldr maxValue]].origin];
    [[self button] setHidden:NO];
}
- (NSString*)getMarkAsString
{
    return QTStringFromTime([self qtMark]);
}
@end
