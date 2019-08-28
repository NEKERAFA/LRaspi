/**
 * interface/explorer.h - NEKERAFA - 28th aug 2019
 * 
 * See Copyright Notice in lraspi.h 
 */

#ifndef LRAPI_INTERFACE_EXPLORER_H
#define LRAPI_INTERFACE_EXPLORER_H

namespace lraspi
{

namespace explorer
{

/**
 * @brief Loads the resources
 */
void load();

/**
 * @brief Update controls
 */
void update();

/**
 * @brief Draw the explorer
 */
void draw();

/**
 * @brief Closes the explorer
 * 
 */
void close();

} // namespace explorer

} // namespace lraspi

#endif // LRAPI_INTERFACE_EXPLORER_H