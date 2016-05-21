<?php

namespace Xpl;


interface Comparator
{

    /**
     * Compares two items.
     *
     * @param mixed $a 
     * @param mixed $b 
     * @return int 
     */
    public function compare($a, $b);

}
