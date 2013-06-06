
#ifndef  JSONVALUE_H
#define  JSONVALUE_H

/*
 * =====================================================================================
 *        Class:  JsonValue
 *  Description:  
 * =====================================================================================
 */
class JsonValue {
	public:
		/* ====================  LIFECYCLE     ======================================= */
		JsonValue();                             /* constructor */

		/* ====================  ACCESSORS     ======================================= */
		std::string getString() const;
		int getInteger() const;
		double getReal() const;
		std::vector<JsonValue *> * getArray() const;
		bool getBoolean() const;
		JsonObject * getObject() const;
		/* ====================  MUTATORS      ======================================= */

		/* ====================  OPERATORS     ======================================= */

	protected:
		/* ====================  METHODS       ======================================= */

		/* ====================  DATA MEMBERS  ======================================= */

	private:
		/* ====================  METHODS       ======================================= */

		/* ====================  DATA MEMBERS  ======================================= */

}; /* -----  end of class JsonValue  ----- */

#endif   /* ----- #ifndef JsonValue_INC  ----- */
