// Copyright 2018 Yahoo Holdings. Licensed under the terms of the Apache 2.0 license. See LICENSE in the project root.
package com.yahoo.vespa.model.ml;

import com.yahoo.path.Path;

/**
 * Models used in a rank profile has the rank profile name as name space while gGlobal model names have no namespace
 *
 * @author bratseth
 */
public class ModelName {

    /** The namespace, or null if none */
    private String namespace;
    private String name;
    private String fullName;

    public ModelName(String name) {
        this(null, name);
    }

    public ModelName(String namespace, Path modelPath) {
        this(namespace, modelPath.toString().replace("/", "_"));
    }

    private ModelName(String namespace, String name) {
        this.namespace = namespace;
        this.name = name;
        this.fullName = (namespace != null ? namespace + "." : "") + name;
    }

    /** Returns true if the local name of this is not in a namespace */
    public boolean isGlobal() { return namespace == null; }

    /** Returns the namespace, or null if this is global */
    public String namespace() { return namespace; }
    public String localName() { return name; }
    public String fullName() { return fullName; }


    @Override
    public boolean equals(Object o) {
        if (o == this) return true;
        if ( ! (o instanceof ModelName)) return false;
        return ((ModelName)o).fullName.equals(this.fullName);
    }

    @Override
    public int hashCode() { return fullName.hashCode(); }

    @Override
    public String toString() { return fullName; }

}