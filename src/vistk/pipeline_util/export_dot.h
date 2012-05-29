/*ckwg +5
 * Copyright 2011-2012 by Kitware, Inc. All Rights Reserved. Please refer to
 * KITWARE_LICENSE.TXT for licensing information, or contact General Counsel,
 * Kitware, Inc., 28 Corporate Drive, Clifton Park, NY 12065.
 */

#ifndef VISTK_PIPELINE_UTIL_EXPORT_DOT_H
#define VISTK_PIPELINE_UTIL_EXPORT_DOT_H

#include "pipeline_util-config.h"

#include <vistk/pipeline/types.h>

#include <iosfwd>
#include <string>

/**
 * \file export_dot.h
 *
 * \brief Functions export a dot file for a pipeline.
 */

namespace vistk
{

/**
 * \brief Exports a dot graph for a pipeline.
 *
 * Outputs a DOT formatted graph which represents the pipeline's requested
 * layout.
 *
 * \throws null_pipeline_export_dot_exception Thrown when \p pipe is \c NULL.
 *
 * \param ostr The stream to export to.
 * \param pipe The pipeline to export.
 * \param graph_name The name of the graph.
 */
void VISTK_PIPELINE_UTIL_EXPORT export_dot(std::ostream& ostr, pipeline_t const pipe, std::string const& graph_name);

/**
 * \brief Exports a dot graph for a pipeline.
 *
 * Outputs a DOT formatted graph which represents the pipeline after connections
 * have been resolved.
 *
 * \throws null_pipeline_export_dot_exception Thrown when \p pipe is \c NULL.
 * \throws pipeline_not_setup_exception Thrown when \p pipe is not setup.
 * \throws pipeline_not_ready_exception Thrown when \p pipe has not been setup successfully.
 *
 * \param ostr The stream to export to.
 * \param pipe The pipeline to export.
 * \param graph_name The name of the graph.
 */
void VISTK_PIPELINE_UTIL_EXPORT export_dot_setup(std::ostream& ostr, pipeline_t const pipe, std::string const& graph_name);

}

#endif // VISTK_PIPELINE_UTIL_EXPORT_DOT_H
