<?php

namespace xpl\Http\Response;

use xpl\Http\Response as HttpResponse;

interface FormatStrategyInterface {
	
	public function format(HttpResponse $response);
	
	public function getMimetype();
	
}
