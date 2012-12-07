//
//  Firebase.h
//  Firebase
//
//  Created by Vikrum Nijjar on 8/2/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FQuery.h"
#import "FDataSnapshot.h"

/**
 * A Firebase reference represents a particular location in your Firebase
 * and can be used for reading or writing data to that Firebase location.
 *
 * This class is the starting point for all Firebase operations. After you've
 * initialized it with initWithUrl: you can use it
 * to read data (ie. on:doCallback:), write data (ie. set:), and to create new 
 * Firebase references (ie. child:).
 */
@interface Firebase : FQuery

/**
 * Initialize this Firebase reference with an absolute URL. 
 *
 * @param url The Firebase URL (ie: https://SampleChat.firebaseIO-demo.com)
 */
- (id)initWithUrl:(NSString *)url;

/**
 * Get a Firebase reference for the location at the specified relative path.
 * The relative path can either be a simple child name (e.g. 'fred') or a 
 * deeper slash-separated path (e.g. 'fred/name/first').
 *
 * @param pathString A relative path from this location to the desired child location.
 * @return A Firebase reference for the specified relative path.
 */
- (Firebase *) child:(NSString *)pathString;

/**
 * Get a Firebase reference for the parent location.
 * If this instance refers to the root of your Firebase, it has no parent, 
 * and therefore parent( ) will return null.
 *
 * @return A Firebase reference for the parent location.
 */
- (Firebase *) parent;

/**
 * Gets last token in a Firebase location (e.g. 'fred' in https://SampleChat.firebaseIO-demo.com/users/fred)
 *
 * @return The name of the location this reference points to.
 */
- (NSString *) name;

/**
 * Gets the absolute URL of this Firebase location. 
 *
 * @return The absolute URL of the referenced Firebase location.
 */
- (NSString *) description;

/**
 * Write data to this Firebase location. This will overwrite any data 
 * at this location and all child locations. 
 *
 * Data types that can be set are:
 * * NSString -- @"Hello World"
 * * NSNumber (also includes boolean) -- @YES, @43, @4.333
 * * NSDictionary -- @{@"key": @"value"}
 * * NSArray
 *
 * The effect of the write will be visible immediately and the corresponding
 * events will be triggered. Synchronization of the data to the Firebase 
 * servers will also be started.
 *
 * Passing null for the new value is equivalent to calling remove:;
 * all data at this location or any child location will be deleted.
 *
 * Note that set: will remove any priority stored at this location, so if priority
 * is meant to be preserved, you should use set:withPriority: instead.
 *
 * @param value The value to be written.
 */
- (void) set:(id)value;

/**
 * The same as set: with a callback that gets triggered after the write operation has
 * been committed to the Firebase servers.
 *
 * @param value The value to be written.
 * @param callback The block to be called after the write has been committed to the Firebase servers.
 */
- (void) set:(id)value onComplete:(void (^)(BOOL status))callback;

/**
 * The same as set: with an additional priority to be attached to the data being written.
 * Priorities are used to order items.
 *
 * @param value The value to be written.
 * @param priority The priority to be attached to that data.
 */
- (void) set:(id)value withPriority:(id)priority;

/**
 * The same as set:withPriority: with a callback that gets triggered after the write operation has
 * been committed to the Firebase servers.
 *
 * @param value The value to be written.
 * @param priority The priority to be attached to that data.
 * @param callback The block to be called after the write has been committed to the Firebase servers.
 */
- (void) set:(id)value withPriority:(id)priority onComplete:(void (^)(BOOL status))callback;

/**
 * Remove the data at this Firebase location. Any data at child locations will also be deleted.
 * 
 * The effect of the delete will be visible immediately and the corresponding events
 * will be triggered. Synchronization of the delete to the Firebase servers will 
 * also be started.
 *
 * remove: is equivalent to calling set:nil
 */
- (void) remove;

/**
 * The same as remove: with a callback that gets triggered after the remove operation has
 * been committed to the Firebase servers.
 *
 * @param callback The block to be called after the remove has been committed to the Firebase servers.
 */
- (void) removeWithOnComplete:(void (^)(BOOL status))callback;

/**
 * Set a priority for the data at this Firebase location.
 * Priorities can be used to provide a custom ordering for the children at a location
 * (if no priorities are specified, the children are ordered by name).
 *
 * You cannot set a priority on an empty location. For this reason
 * setWithPriorit: should be used when setting initial data with a specific priority
 * and setPriority: should be used when updating the priority of existing data.
 *
 * Children are sorted based on this priority using the following rules:
 *
 * Children with no priority (a null priority) come first. They are ordered lexicographically by name.
 * Children with a priority that is parsable as a number come next. They are 
 * sorted numerically by priority first (small to large) and lexicographically by name second (A to z).
 * Children with non-numeric priorities come last. They are sorted lexicographically 
 * by priority first and lexicographically by name second.
 * Setting the priority to null removes any existing priority. 
 * Note that priorities are parsed and ordered as IEEE 754 double-precision floating-point numbers.
 *
 * @param priority The priority to set at the specified location.
 */
- (void) setPriority:(id)priority;

/**
 * The same as setPriority: with a callback block that is called once the priority has
 * been committed to the Firebase servers.
 *
 * @param priority The priority to set at the specified location.
 * @param callback The callback that is triggered after the priority has been written on the servers.
 */
- (void) setPriority:(id)priority onComplete:(void (^)(BOOL status))callback;

/**
 * Push generates a new child location using a unique name and returns a 
 * Firebase reference to it. This is useful when the children of a Firebase
 * location represent a list of items.
 *
 * The unique name generated by push: is prefixed with a client-generated
 * timestamp so that the resulting list will be chronologically-sorted.
 *
 * @return A Firebase reference for the generated location.
 */
- (Firebase *) push;

/**
 * The same as push: with a value to be set: immediately at the generated Firebase location.
 *
 * @param value The value to be set at the generated location.
 * @return A Firebase reference for the generated location.
 */
- (Firebase *) push:(id)value;

/**
 * The same as push: with a callback that is triggered when the data has been written to the 
 * Firebase servers.
 *
 * @param value The value to be set at the generated location.
 * @param callback The callback to be triggered after the write completes.
 * @return A Firebase reference for the generated location.
 */
- (Firebase *) push:(id)value onComplete:(void (^)(BOOL status))callback;

/**
 * on:doCallback: is used to listen for data changes at a particular location.
 * This is the primary way to read data from Firebase. Your callback will be triggered
 * for the initial data and again whenever the data changes.
 *
 * Use off: to stop receiving updates.
 *
 * @param eventType The type of event to listen for.
 * @param callback The callback that should be called with initial data and updates.
 * @return A handle used to unregister this callback later using off:
 */
- (id) on:(FEventType)eventType doCallback:(void (^) (FDataSnapshot *snapshot))callback;

/**
 * This is the same as on:doCallback:, but the callback takes a second argument containing the
 * name of the previous child in a list (when the list is sorted by priority). This
 * is useful when trying to keep lists of data in order.
 *
 * @param eventType The type of event to listen for.
 * @param callback The callback that should be called with initial data and updates.
 * @return A handle used to unregister this callback later using off:
 */
- (id) on:(FEventType)eventType doCallbackWithPrevName:(void (^) (FDataSnapshot *snapshot, NSString *prevName))callback;

/**
 * Detach a callback previously attached with on:. 
 *
 * @param handle The handle returned by the call to on: which we are trying to cancel.
 */
- (void) off:(id)handle;

/**
 * Detach all callbacks previously attached to this Firebase location with on:
 */
- (void) off;

/**
 * This is equivalent to on:doCallback:, except the callback is immediately canceled after the initial data is returned.
 *
 * @param eventType The type of event to listen for.
 * @param callback The callback that should be called with initial data and updates.
 */
- (void) once:(FEventType)eventType doCallback:(void (^) (FDataSnapshot *snapshot))callback;

/**
 * This is equivalent to on:doCallbackWithPrevName:, except the callback is
 * immediately canceled after the initial data is returned.
 *
 * @param eventType The type of event to listen for.
 * @param callback The callback that should be called with initial data and updates.
 */
- (void) once:(FEventType)eventType doCallbackWithPrevName:(void (^) (FDataSnapshot *snapshot, NSString *prevName))callback;

/**
 * Ensure the data at this location is removed when
 * the client is disconnected (due to closing the browser, navigating
 * to a new page, or network issues).
 *
 * removeOnDisconnect: is especially useful for implementing "presence" systems.
 */
- (void) removeOnDisconnect;

/**
 * Ensure the data at this location is set to the specified value when
 * the client is disconnected (due to closing the browser, navigating
 * to a new page, or network issues).
 *
 * setOnDisconnect: is especially useful for implementing "presence" systems,
 * where a value should be changed or cleared when a user disconnects
 * so that he appears "offline" to other users.
 *
 * @param value The value to be set after the connection is lost.
 */
- (void) setOnDisconnect:(id) value;

@end
